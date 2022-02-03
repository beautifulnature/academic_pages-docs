export default class RevampedParagraph extends HTMLElement {
    constructor(){
        super();

        let templateRef = document.querySelector('#revamped-paragraph-template');
        let template = templateRef.content;

        this.append(template.cloneNode(true));
    }
}