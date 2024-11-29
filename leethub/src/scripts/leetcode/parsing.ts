import { map } from '../../constants/Map'
import { LeetcodeData } from '../../types/LeetcodeData'
import { getDateString } from './util'

export async function parseData(): Promise<LeetcodeData> {
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

  // customize: Add Problem ID Time and Memory elements
  const problemId = title.match(/^(\d+)\./);
  if (problemId) {
    const numberBeforeDot = problemId[1];
    console.log(numberBeforeDot);
  } else {
    console.log('No match');
  }

  const timeElement = document.querySelector('.result-time')  // 결과 시간을 담고 있는 클래스명 예시
  const timeBeatsElement = document.querySelector('.result-time-beats') // 시간의 Beats 정보가 있는 부분

  const time = timeElement ? timeElement.textContent?.trim() || '' : ''
  const timeBeats = timeBeatsElement ? timeBeatsElement.textContent?.trim() || '' : ''

  // 메모리 정보 및 beats 추출
  const memoryElement = document.querySelector('.result-memory')  // 결과 메모리를 담고 있는 클래스명 예시
  const memoryBeatsElement = document.querySelector('.result-memory-beats')  // 메모리의 Beats 정보가 있는 부분

  const memory = memoryElement ? memoryElement.textContent?.trim() || '' : ''
  const memoryBeats = memoryBeatsElement ? memoryBeatsElement.textContent?.trim() || '' : ''
  // customize
  return {
    title,
    description,
    constraints,
    codeSnippet,
    language,
    link,
    problemId: problemId ? problemId[1] : '',
    time,
    timeBeats,
    memory,
    memoryBeats
  }
}

export function convertSingleCharToDoubleChar(text: string): string {
  return text.replace(/[!%&()*+,\-./:;<=>?@\[\\\]^_`{|}~ ]/g, function (m) {
    return map[m as keyof typeof map]
  })
}
