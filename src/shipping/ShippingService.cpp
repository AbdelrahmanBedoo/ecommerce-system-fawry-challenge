#include "ShippingService.h"
#include <bits/stdc++.h>
#include "../interfaces/IShippable.h"
using namespace std;

void ShippingService::ship(const vector<CartItem>& items) {
    double totalWeight = 0;
    cout << "** Shipment notice **\n";

    for (const auto& i : items) {
        auto* shp = dynamic_cast<IShippable*>(i.product.get());
        if (shp) {
            double w = shp->getWeight(i.quantity);
            cout << i.quantity << "x " << shp->getName() << " " << (w * 1000) << "g\n";
            totalWeight += w;
        }
    }
    cout << "Total package weight " << totalWeight << "kg\n\n";
}

