var scores = [];

function grade_quiz() {
    var correctAnswers = 0;
    var totalQuestions = 10;

    if (document.getElementById("q1_correct1").checked && !document.getElementById("q1_wrong1").checked &&
        !document.getElementById("q1_wrong2").checked) {
        correctAnswers++;
    }

    if (document.getElementById("q2_correct").checked) {
        correctAnswers++;
    }

    if (parseInt(document.getElementById("q3_correct").value) === 3) {
        correctAnswers++;
    }

    if (document.getElementById("q4_correct").checked) {
        correctAnswers++;
    }

    if (document.getElementById("q5_correct").checked) {
        correctAnswers++;
    }

    if (parseInt(document.getElementById("q6_correct").value) === 3) {
        correctAnswers++;
    }

    if (document.getElementById("q7_correct1").checked && document.getElementById("q7_correct2").checked &&
        !document.getElementById("q7_wrong1").checked && !document.getElementById("q7_wrong2").checked) {
        correctAnswers++;
    }

    if (parseInt(document.getElementById("q8_correct").value) === 2) {
        correctAnswers++;
    }

    if (document.getElementById("q9_correct").checked) {
        correctAnswers++;
    }

    if (document.getElementById("q10_correct").checked) {
        correctAnswers++;
    }
    
    
    // Calculate score
    var score = (correctAnswers / totalQuestions) * 100;
    var message = "Your final score is " + correctAnswers + "/" + totalQuestions + " = " + score.toFixed(2) + "%: ";

    // SCORING LOGIC
    if (score >= 80) {
        message += "Advanced";
    } else if (score >= 50 && score <= 70) {
        message += "Intermediate";
    } else {
        message += "Beginner";
    }

    // Store the score in the scores array
    scores.push(message);

    // Output the result to textarea
    document.getElementById("resultTextarea").value = message;

    // Output the result to text input
    document.getElementById("resultInput").value = message;

    // Output the result to paragraph
    document.getElementById("messages").innerHTML = message;

    // Display all scores
    displayScores();
}

function displayScores() {
    var scoreList = "<h3>All Scores:</h3>";
    for (var i = 0; i < scores.length; i++) {
        scoreList += scores[i] + "<br>";
    }
    document.getElementById("allScores").innerHTML = scoreList;
}

window.addEventListener("load", function () {
    document.getElementById("submit").addEventListener("click", grade_quiz, false);
    displayScores(); // Display all scores on page load
}, false);