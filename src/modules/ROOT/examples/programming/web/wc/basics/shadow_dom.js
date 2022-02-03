// get the reference to the div
let shadowRootEl = document.querySelector('.entry');

// mark it as a shadow root
let shadowRoot = shadowRootEl.attachShadow({mode: 'open'});

// create a random span tag
// that can be appended to the shadow root
let childEl = document.createElement('span');
childEl.innerText = 'Hello shadow DOM';

// append the span tag to the shadow root
shadowRoot.appendChild(childEl);