console.log("Javascript is working!");

// Add a click event to navigate to another page
document.getElementById("navigate-button").addEventListener("click", function () {
    console.log("Going to another page...");
    window.location.href = "another-page.html";
});