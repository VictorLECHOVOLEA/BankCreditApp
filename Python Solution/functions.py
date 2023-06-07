# my_dict = {}
# # 
# def read_json_to_dict():
#     #
    
# def export_dict to Json():
#     #
    
# def add_to_dict():
#     #
    
# def remove_from_dict():
#     #
    
# def get_today():
#     #from time import time

# def welcome():
#     print('Welcome...')

# def login():
#     # longin

# def logout():
#     #


# #my list of default shops:
# shops = [
#     {
#         'name': 'Dedeman',
#         'rates': [
#             {'over_200': 3,
#             'over_500': 6,
#             'over_1000': 9,
#             'over_1500': 12,
#             }
#         ]
#     },
#     {
#         'name': 'Shop 2',
#         'rates': [
#             {'min': 5, 'max': 15},
#             {'min': 16, 'max': 25},
#             {'min': 26, 'max': 35}
#         ]
#     },
#     {
#         'name': 'Shop 3',
#         'rates': [
#             {'min': 10, 'max': 20},
#             {'min': 21, 'max': 30},
#             {'min': 31, 'max': 40}
#         ]
#     }
# ]

# # Accessing the data
# print(shops[0]['name'])  # Output: Shop 1
# print(shops[1]['rates'][2])  # Output: {'min': 26, 'max': 35}



"""
i would like to make a function that would: create a dictionary of shops with a list of 
credit rates by shop, and rates available depending on the sum borrowe.
I would like to create a function that would request the user for a 
transaction, and for that transaction to ask for the shop name, transaction 
value and transaction rates. Here at transaction rates, if the shop is in the dictionary, 
suggest a rate depending on the value, if not, let the user to introduce the rates number.


Certainly! I can help you create a function that prompts the user for transaction details and uses the existing dictionary of shops to suggest rates based on the transaction value. Here's an example:

python


def make_transaction():
    # Dictionary of shops with credit rates
    shops = {
        'Shop 1': [
            {'min': 0, 'max': 1000, 'rate': 0.05},
            {'min': 1001, 'max': 5000, 'rate': 0.08},
            {'min': 5001, 'max': float('inf'), 'rate': 0.1}
        ],
        'Shop 2': [
            {'min': 0, 'max': 2000, 'rate': 0.06},
            {'min': 2001, 'max': 10000, 'rate': 0.09},
            {'min': 10001, 'max': float('inf'), 'rate': 0.12}
        ],
        'Shop 3': [
            {'min': 0, 'max': 1500, 'rate': 0.07},
            {'min': 1501, 'max': 7000, 'rate': 0.1},
            {'min': 7001, 'max': float('inf'), 'rate': 0.13}
        ]
    }

    # Get transaction details from the user
    shop_name = input("Enter the shop name: ")
    transaction_value = float(input("Enter the transaction value: "))

    # Check if the shop is in the dictionary
    if shop_name in shops:
        # Find the appropriate rate based on the transaction value
        rates = shops[shop_name]
        for rate in rates:
            if rate['min'] <= transaction_value <= rate['max']:
                suggested_rate = rate['rate']
                break
        else:
            suggested_rate = None

        if suggested_rate is not None:
            print("Suggested rate for this transaction:", suggested_rate)
        else:
            print("No suggested rate available for this transaction value.")
    else:
        print("Shop not found in the dictionary.")

# Example usage
make_transaction()


In this example, the make_transaction() function prompts the user for the shop name and transaction value. It then checks if the shop exists in the shops dictionary. If the shop is found, it iterates through the rate ranges for that shop and suggests the appropriate rate based on the transaction value. If no rate range is found for the transaction value, it informs the user that no suggested rate is available.

Note that the rate ranges are stored as dictionaries within a list for each shop in the shops dictionary. You can modify the rate ranges and add more shops to suit your needs.
"""

def make_transaction():
    # Dictionary of shops with credit rates
    shops = {
        'Dedeman': [
            {'min': 0, 'max': 200, 'rate': 1},
            {'min': 201, 'max': 500, 'rate': 3},
            {'min': 501, 'max': 1000, 'rate': 6},
            {'min': 1001, 'max': 1500, 'rate': 9},
            {'min': 1501, 'max': float('inf'), 'rate': 12}
        ],
        'Shop 2': [
            {'min': 0, 'max': 2000, 'rate': 0.06},
            {'min': 2001, 'max': 10000, 'rate': 0.09},
            {'min': 10001, 'max': float('inf'), 'rate': 0.12}
        ],
        'Shop 3': [
            {'min': 0, 'max': 1500, 'rate': 0.07},
            {'min': 1501, 'max': 7000, 'rate': 0.1},
            {'min': 7001, 'max': float('inf'), 'rate': 0.13}
        ]
    }

    # Get transaction details from the user
    shop_name = input("Enter the shop name: ")
    transaction_value = float(input("Enter the transaction value: "))

    # Check if the shop is in the dictionary
    if shop_name in shops:
        # Find the appropriate rate based on the transaction value
        rates = shops[shop_name]
        for rate in rates:
            if rate['min'] <= transaction_value <= rate['max']:
                suggested_rate = rate['rate']
                break
        else:
            suggested_rate = None

        if suggested_rate is not None:
            print("Suggested rate for this transaction:", suggested_rate)
        else:
            print("No suggested rate available for this transaction value.")
    else:
        print("Shop not found in the dictionary.")

# Example usage
make_transaction()
