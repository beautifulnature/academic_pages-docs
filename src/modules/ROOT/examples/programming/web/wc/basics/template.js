// get the reference to the template
let templateReferenceJS = document.querySelector('#my-template');

// get the content node
let templateContentJS = templateReferenceJS.content;

// clone the template content
// and append it to the target div
document.querySelector('#target-template').appendChild(templateContentJS.cloneNode(true));