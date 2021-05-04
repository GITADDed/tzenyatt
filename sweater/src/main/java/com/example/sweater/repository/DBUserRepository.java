package com.example.sweater.repository;

import com.example.sweater.domain.DBUser;
import org.springframework.data.jpa.repository.JpaRepository;

public interface DBUserRepository extends JpaRepository<DBUser, Long> {
    DBUser findDBUserByUsername(String username);
}
