export default class CompanyHeader extends HTMLElement {
    constructor() {
        super();
        this.icon = "newicon.jpeg";
        this.shadowObj = this.attachShadow({ mode: "open" });
        this.render();
    }

    static get observedAttributes() {
        return ["icon", "page-name"];
    }

    attributeChangedCallback(name, oldValue, newValue) {
        if (name == "icon") {
            this.icon = newValue;
        }

        if (name == "page-name") {
            this.pageName = newValue;
        }

        this.render();
    }

    render() {
        this.shadowObj.innerHTML = this.getTemplate();
    }

    getTemplate() {
        return `
            <a href="">
                <img class="icon" src="${this.icon}" />
            </a>
            <h1 class="heading">${this.pageName}</h1>
            <div>
                <a class="header-links" href="/home.html">Home</a>
                <a class="header-links" href="/aboutus.html">About Us</a>
            </div>
            <style>
                :host {
                    display: flex;
                    background: #44afdc;
                    align-items: center;
                    padding: 0 10px;
                }
                .icon {
                    width: 50px;
                    height: 50px;
                    border-radius: 50%;
                }
                .heading {
                    flex: 1;
                    color: white;
                    padding-left: 20px;
                }
                .header-links {
                    text-decoration: none;
                    padding: 20px;
                    color: white;
                }
            </style>
            `;
    }
}
