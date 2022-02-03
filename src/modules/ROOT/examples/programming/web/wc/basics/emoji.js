class SmileyEmoji extends HTMLElement {
    constructor(){
        super();
        this.innerText = '\uD83D\uDE00';
    }
}

customElements.define('smiley-emoji', SmileyEmoji);