let login = document.querySelector("#login_bttn button");

function changeBgColor()
{
  document.body.style.backgroundColor = "green";
}

function login_input(e)
{
  let id = document.forms[0].elements[0].value;
  let pw = document.forms[0].elements[1].value;

  if(id === "admin" && pw === "admin123!")
  {
    alert("로그인 성공!");
  }
  else
  {
    alert("로그인 실패!");
    changeBgColor();
  }

  e.preventDefault(); // HTML의 <button>은 클릭시 자동으로 새로고침 되는데 새로고침 되면서 배경색이 원래대로 돌아옵니다.
                      // 따라서 <button>의 동작을 막기 위해 preventDefault 함수를 사용했습니다.
}

login.addEventListener("click", login_input);