<<<<<<< HEAD
let main = function(){
    const mainHeader = document.getElementById("mainHeader");
    mainHeader.addEventListener('click', function(){
        mainHeader.style.backgroundColor = 'Red';
    });
}

document.addEventListener("DOMContentLoaded", main)
let Component = (function(){
    var init = function(){

    };
    
    return {
        Init: init
    }
 })();
=======
document.addEventListener("DOMContentLoaded", main);
function main(){
    let div = document.getElementById("id1");
    div.addEventListener("click", _ => {
        div.style.backgroundColor = "red";
    });
}
>>>>>>> 1b3bb1d52252f39418c8467b4f1028f0f25c7801
