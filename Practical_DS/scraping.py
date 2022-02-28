import requests
import re 
from bs4 import BeautifulSoup

link_122 = "https://cs.cmu.edu/~15122/schedule.shtml"
page = requests.get(link_122)
print(page.status_code)
soup = BeautifulSoup(page.content, 'html.parser')

all_links = []
links = soup.find_all('a')

for ahref in links:
    text = ahref.text
    text = text.strip() if text is not None else ''

    href = ahref.get('href')
    href = href.strip() if href is not None else ''
    all_links.append({"href": href, "text": text})
    print(ahref)
