/******* 베이징과 서울의 UTC 시차 *******/
const beijingTimeDiff = 8 * 60 * 60 * 1000; // 베이징 시간은 UTC+8입니다.
const seoulTimeDiff = 9 * 60 * 60 * 1000; // 서울의 시간은 UTC+9입니다.

/******* UTC시간 가져오기 *******/
function getCurrentUTC()
{
  let userCurrentTime = new Date(); // 사용자 PC 설정 시간
  let currentUTC = userCurrentTime.getTime() + (userCurrentTime.getTimezoneOffset() * 60 * 1000); // 1970년 1월 1일 부터 계산한 UTC시간

  return currentUTC;
}

/*******  베이징 시간 표시하기 *******/
const BeijingTimeDisplay = document.querySelector("#display");

function showDay(day)
{
  switch(day)
  {
    case 0: 
      return "일요일";
    case 1:  
      return "월요일";
    case 2: 
      return "화요일";
    case 3: 
      return "수요일";
    case 4: 
      return "목요일";
    case 5: 
      return "금요일";
    case 6: 
      return "토요일";
  }
}

function showBeijingTime()
{
  let utc = getCurrentUTC();
  let beijingCurrentTime = new Date(utc + beijingTimeDiff); // 베이징 현재 시간
  
  let year = beijingCurrentTime.getFullYear();
  let month = beijingCurrentTime.getMonth() + 1;
  let date = beijingCurrentTime.getDate();
  let day1 = beijingCurrentTime.getDay();
  let day2 = showDay(day1);

  let hrs = beijingCurrentTime.getHours();
  let mins = beijingCurrentTime.getMinutes();
  let secs = beijingCurrentTime.getSeconds();
  let period = "AM";

  if (hrs === 0) 
  {
    hrs = 12;
  } 
  else if (hrs > 12) 
  {
    hrs = hrs - 12;
    period = "PM";
  }
    
  hrs = (hrs < 10) ? "0" + hrs : hrs;
  mins = (mins < 10) ? "0" + mins : mins;
  secs = (secs < 10) ? "0" + secs : secs;

  BeijingTimeDisplay.innerHTML = `
    ${year}년  ${month}월  ${date}일  ${day2}<br>
    ${period}  ${hrs} : ${mins} : ${secs}`;
}

/******* D_Day 표시하기 *******/
const D_DayDisplay = document.querySelector("#D_Day");
const travelDate = new Date("01/01/2024"); // 2024년 1월 1일을 베이징 여행 날짜로 정했습니다.

function showD_Day()
{
  let utc = getCurrentUTC();
  let seoulCurrentTime = new Date(utc + seoulTimeDiff); // 서울 현재 시간

  let D_Day = Math.round((travelDate.getTime() - seoulCurrentTime.getTime()) / (1000 * 60 * 60 * 24));
  D_DayDisplay.innerText = `${D_Day}`;
}

showBeijingTime();
setInterval(showBeijingTime, 1000);

showD_Day();
setInterval(showD_Day, 1000);