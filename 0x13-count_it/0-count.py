#!/usr/bin/python3
"""Count it!"""


import requests


def get_posts(subreddit, word_list, word_dict, sub_dict, after="", count=0):
    """Retrieve posts"""
    url = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    h = {"User-Agent": "faspen01"}
    p = {"after": after, "count": count, "limit": 100}

    response = requests.get(url, headers=h, params=p, allow_redirects=False)

    try:
        posts = response.json()
        if (response.status_code > 300):
            raise BaseException
    except BaseException:
        return

    posts = posts.get("data")
    after = posts.get("after")
    count += posts.get("dist")
    for c in posts.get("children"):
        title = c.get("data").get("title").lower().split()
        for w in word_list:
            if (w.lower() in title):
                t = len([t for t in title if t == w.lower()])
                inst = word_dict.get(w)
                word_dict[w] = t if inst is None else word_dict[w] + t

    if after is None:
        if len(word_dict) == 0:
            print("")
            return
        tmp = []

        for item, val in word_dict.items():
            tmp.append((val, item))
        tmp.sort(reverse=True)

        for t in tmp:
            item, val = t[0], t[1]
            print("{}: {}".format(val, item))
    else:
        get_posts(subreddit, word_list, word_dict, after, count)


def count_words(subreddit, word_list):
    """Queries the Reddit API and sorts articles"""
    word_dict = {}
    after = ""
    count = 0

    return get_posts(subreddit, word_list, word_dict, after, count)
