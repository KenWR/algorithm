import { map } from '../../constants/Map'
import { LeetcodeData } from '../../types/LeetcodeData'
import { getDateString } from './util'

function getQuestionFrontendId(): string | null {
  // '__NEXT_DATA__'라는 id를 가진 script element를 가져옵니다.
  const scriptElement = document.getElementById('__NEXT_DATA__') as HTMLScriptElement;

  // scriptElement가 존재하고, 데이터가 올바른 JSON 형식인지 확인합니다.
  if (scriptElement && scriptElement.innerHTML) {
    try {
      // innerHTML을 JSON으로 파싱합니다.
      const data = JSON.parse(scriptElement.innerHTML);

      // 'questionFrontendId' 값을 변수에 저장하고 리턴합니다.
      return data.questionFrontendId || null; // 값이 없으면 null을 리턴
    } catch (error) {
      console.error("JSON 파싱 오류:", error);
      return null; // 파싱 오류가 발생하면 null을 리턴
    }
  } else {
    console.error("Script element를 찾을 수 없습니다.");
    return null; // element가 없으면 null을 리턴
  }
}

export async function parseData(): Promise<LeetcodeData> {
  const questionFrontendId = getQuestionFrontendId() || '';

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
    questionFrontendId
  }
}

export function convertSingleCharToDoubleChar(text: string): string {
  return text.replace(/[!%&()*+,\-./:;<=>?@\[\\\]^_`{|}~ ]/g, function (m) {
    return map[m as keyof typeof map]
  })
}
