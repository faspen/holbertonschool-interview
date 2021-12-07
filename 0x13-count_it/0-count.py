#!/usr/bin/python3
"""Count it!"""


import requests


def count_words(subreddit, word_list, num={}, after=""):
    """Queries the Reddit API and sorts articles"""
    if len(num) <= 0:
        for obj in word_list:
            num[obj] = 0
    if after is None:
        word_list = [[k, v] for k, v in num.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))

        for i in word_list:
            if i[1]:
                print("{}: {}".format(i[0].lower(), i[1]))
        return None

    url = "https://api.reddit.com/r/{}/hot".format(subreddit)
    p = {'limit': 100, 'after': after}
    h = {'user-agent': 'my-app/0.0.1'}
    response = requests.get(url, headers=h, params=p, allow_redirects=False)

    if response.status_code == 200:
        after = response.json().get("data").get("after")
        children = response.json().get("data").get("children")

        for c in children:
            title = c.get("data").get("title")
            low = [x.lower() for x in title.split(' ')]

            for w in word_list:
                num[w] += low.count(w.lower())
    else:
        return None
    count_words(subreddit, word_list, num, after)
