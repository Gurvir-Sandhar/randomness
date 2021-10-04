const PORT = 8000;
const axios = require('axios');
const cheerio = require('cheerio');


axios('https://whats.new/shortcuts/')
    .then(response => {
        const html = response.data;
        const $ = cheerio.load(html);

        const shortcuts = [];

        $('.data-table__row', html).each(function() {
            const obj = {};
            const domains = [];

            obj.company = $(this).find('.data-table__cell--company').text();
            const links = $(this).find('.data-table__cell--domain');
            $(links).find('.link').each(function() {
                domains.push($(this).text());
            })
            obj.domains = domains;
            obj.description = $(this).find('.data-table__cell--description').text();

            shortcuts.push(obj);
        })
        console.log(shortcuts)
    })
