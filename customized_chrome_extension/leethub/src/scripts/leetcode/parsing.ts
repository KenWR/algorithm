import { map } from '../../constants/Map'
import { LeetcodeData } from '../../types/LeetcodeData'
import { getDateString } from './util'

export async function parseData(): Promise<LeetcodeData> {
  const dataSet = document.getElementById(`__NEXT_DATA__`);
  const textContent = dataSet instanceof HTMLElement ? dataSet.textContent || '' : '';
  const difficultyMatch = textContent.match(/"difficulty":"([^"]+)"/);
  const difficulty = difficultyMatch ? difficultyMatch[1] : 'Unknown'; // "difficulty" 값 추출 (easy, medium, hard)

  const title =
    document.querySelector('title')?.textContent?.replace(' - LeetCode', '') ||
    ''

  const metaDescription =
    document
      .querySelector('meta[name="description"]')
      ?.getAttribute('content') || ''
  const descriptionAndConstraints = metaDescription.split('Constraints:')

  const description = descriptionAndConstraints[0].trim()

  let constraints: string[] = []
  if (descriptionAndConstraints.length > 1) {
    constraints = descriptionAndConstraints[1]
      .split(',')
      .map((constraint: string) => constraint.trim())
  }

  const link =
    document
      .querySelector('meta[property="og:url"]')
      ?.getAttribute('content') || ''

  const codeBlock = document.querySelector('pre')
  const codeSnippet = codeBlock ? codeBlock.textContent || '' : ''

  const languageElement = document.querySelector('[data-mode-id]')
  const language = languageElement
    ? languageElement.getAttribute('data-mode-id') || ''
    : ''

  return {
    title,
    description,
    constraints,
    codeSnippet,
    language,
    link,
    difficulty
  }
}

export function convertSingleCharToDoubleChar(text: string): string {
  return text.replace(/[!%&()*+,\-./:;<=>?@\[\\\]^_`{|}~ ]/g, function (m) {
    return map[m as keyof typeof map]
  })
}
