package com.example.sweater.controller;

import com.example.sweater.domain.DBUser;
import com.example.sweater.domain.Role;
import com.example.sweater.repository.DBUserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.Collection;
import java.util.Collections;
import java.util.Map;

@Controller
public class RegistrationController {
    @Autowired
    private DBUserRepository dbUserRepository;

    @GetMapping("/registration")
    public String registration() {
        return "registration";
    }

    @PostMapping("/registration")
    public String addUser(DBUser user, Map<String, Object> model) {
        DBUser userFromDB = dbUserRepository.findDBUserByUsername(user.getUsername());
        if (userFromDB != null) {
            model.put("user", "User exists!");
            return "registration";
        }
        user.setActive(true);
        user.setRoles(Collections.singleton(Role.DBUSER));
        dbUserRepository.save(user);
        return "redirect:/login";
    }
}
