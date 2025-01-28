#test サイトデータの抽出
import requests
from bs4 import BeautifulSoup
import schedule
import time
import discord
from discord.ext import tasks

DISCORD_TOKEN = 'YOUR_DISCORD_BOT_TOKEN'
CHANNEL_ID = 'YOUR_CHANNEL_ID'

def get_fgo_news():
    url = 'https://news.fate-go.jp/'
    res = requests.get(url)
    res.encoding = res.apparent_encoding
    soup = BeautifulSoup(res.text, "html.parser")
    soup = BeautifulSoup(res.content.decode("utf-8", "ignore"), "html.parser")
    elems = soup.select('li>p')

    titles=[]
    dates=[]
    links=[]

    for i in range(0,20,2):
        dates.append(elems[i].contents)
        titles.append(elems[i+1].contents)

        parent_li = elems[i].find_parent('li')
        elems1 = parent_li.select('a')
        links.append(elems1[0].attrs['href'])
    
    return titles,dates,links

old_titles, old_dates, old_links = get_fgo_news()

def fetch_and_compare():
    global old_titles, old_dates, old_links
    new_titles, new_dates, new_links = get_fgo_news()

    added_titles = [title for title in new_titles if title not in old_titles]
    added_dates = [date for date in new_dates if date not in old_dates]
    added_links = [link for link in new_links if link not in old_links]

    # 新しいデータがある場合のみ表示
    if added_titles or added_dates or added_links:
        print("New Titles:", added_titles)
        print("New Dates:", added_dates)
        print("New Links:", added_links)
    
        # 古いデータを更新
        old_titles = new_titles
        old_dates = new_dates
        old_links = new_links

# スケジュール設定
schedule.every().day.at("18:00").do(fetch_and_compare)
schedule.every().day.at("18:05").do(fetch_and_compare)
schedule.every().day.at("18:10").do(fetch_and_compare)

# スケジュールを実行
while True:
    schedule.run_pending()
    time.sleep(1)