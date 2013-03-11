//
//  DataStoreSqlite.h
//  gai++
//
//  Created by Nathan Holmberg on 8/03/13.
//  Copyright (c) 2013 nshgraph. All rights reserved.
//

#ifndef gai___DataStoreSqlite_h
#define gai___DataStoreSqlite_h

#include "DataStore.h"
#include <string>
#include <list>
#include <map>
#include "Hit.h"

class sqlite3;

namespace GAI
{
    class DataStoreSqlite : public DataStore
    {
    public:
        DataStoreSqlite( const std::string& path );
        ~DataStoreSqlite();
        // Functions for managing the datastore as a whole
        bool open();
        bool save();
        void close();
        
        // Functions for managing the datastore state
        bool hasChanges() const;
        
        bool deleteAllEntities();
        int entityCount();
        
        // Functions for managing hits in the datastore
        bool deleteAllHits();
        bool addHit(const Hit& hit);
        int hitCount();
        std::list<Hit> fetchHits(const unsigned int limit, bool removeFetchedFromDataStore);
        
        // Functions for managing properties in the datastore
        bool deleteAllProperties();
        bool addProperty(const std::string& name, const std::string& value);
        std::string fetchProperty( const std::string& name );
        std::map<std::string,std::string> fetchProperties();
        int propertyCount();
    private:
        sqlite3* mDB;
        std::string mPath;
        bool mbHasChanges;
    };
}


#endif