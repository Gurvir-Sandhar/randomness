//returns a string as a url slug
function urlSlug(title) {
    return title
        .split(" ")
        .filter(word => word != "")
        .join("-")
        .toLowerCase()
}
