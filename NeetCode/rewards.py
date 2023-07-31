import webbrowser
import random
import urllib.parse
import time

# List of search queries to choose from
i =0
for i in range(25) :
    queries = ['life', 'money', 'knowledge', 'health', 'love', 'happiness', 'success', 'wisdom', 'friendship', 'opportunity',
         'peace', 'family', 'career', 'travel', 'education', 'talent', 'beauty', 'creativity', 'passion', 'faith',
         'adventure', 'courage', 'perseverance', 'purpose', 'spirituality', 'innovation', 'imagination', 'respect',
         'responsibility', 'gratitude', 'generosity', 'kindness', 'loyalty', 'honesty', 'integrity', 'humility',
         'confidence', 'ambition', 'leadership', 'teamwork', 'communication', 'adaptability', 'problem-solving',
         'self-discipline', 'patience', 'tolerance', 'forgiveness', 'compassion', 'empathy', 'charity', 'justice',
         'freedom', 'equality', 'diversity', 'environment', 'sustainability', 'technology', 'art', 'music',
         'literature', 'film', 'food', 'fashion', 'sports', 'nature', 'animals', 'space', 'history', 'culture',
         'politics', 'economy', 'science', 'mathematics', 'engineering', 'medicine', 'law', 'philosophy', 'religion',
         'mythology', 'psychology', 'sociology', 'anthropology', 'linguistics', 'education', 'media', 'journalism',
         'social media', 'marketing', 'entrepreneurship', 'finance', 'investment', 'taxes', 'retirement',
         'insurance', 'real estate', 'transportation', 'aviation', 'automobiles', 'ships', 'trains', 'buses',
         'bicycles', 'motorcycles', 'trucks', 'construction', 'manufacturing', 'mining', 'energy', 'renewables',
         'nuclear power', 'oil', 'gas', 'coal']
    # queries = ['apple', 'python programming', 'stock market', 'artificial intelligence', 'travel destinations']

    # Choose a random search query from the list
    random_query = random.choice(queries)

    # Encode the query for use in the search URL
    encoded_query = urllib.parse.quote(random_query)

    # Construct the Bing search URL
    search_url = f"https://www.bing.com/search?q={encoded_query}"

    # Open the search URL in the default web browser
    webbrowser.open(search_url)

    time.sleep(2)
    

    # ENTITY_LENGTH = 10
