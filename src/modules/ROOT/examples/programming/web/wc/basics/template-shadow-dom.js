// get the reference to the template
let templateReference = document.querySelector('#my-template-shadow-dom');

// get the content node
let templateContent = templateReference.content;

// get the reference to target DOM
let targetDOM = document.querySelector('#target-template-shadow-dom');

// add a shadow root to the target reference DOM
let targetShadowRoot = targetDOM.attachShadow({mode: 'open'});

// clone the template content
// and append it to the target div
targetShadowRoot.appendChild(templateContent.cloneNode(true));