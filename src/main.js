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
