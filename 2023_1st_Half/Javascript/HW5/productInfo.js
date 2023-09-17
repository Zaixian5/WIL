let xhr = new XMLHttpRequest();
xhr.open('GET', 'https://reqres.in/api/products/10', true);
xhr.send();

xhr.onreadystatechange = function(){
  if(xhr.readyState === 4 && xhr.status === 200){
    let products = JSON.parse(xhr.responseText)

    document.getElementById("product-name").innerHTML = `<span style="font-weight: bold;">상품명:</span> ${products.data.name}`;
    document.getElementById("product-year").innerHTML = `<span style="font-weight: bold;">생산년도:</span> ${products.data.year}`;
  }
}