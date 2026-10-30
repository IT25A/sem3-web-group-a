document.addEventListener("DOMContentLoaded", main);
function main(){
    let div = document.getElementById("id1");
    div.addEventListener("click", _ => {
        div.style.backgroundColor = "red";
    });
}