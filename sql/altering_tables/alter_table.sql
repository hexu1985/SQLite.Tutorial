
alter table contacts
        add column email text not null default '' collate nocase;
