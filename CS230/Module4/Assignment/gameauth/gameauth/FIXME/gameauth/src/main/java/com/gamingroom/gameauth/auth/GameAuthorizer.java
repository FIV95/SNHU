package com.gamingroom.gameauth.auth;

import javax.ws.rs.container.ContainerRequestContext;

import org.glassfish.jersey.server.ContainerRequest;


import io.dropwizard.auth.Authorizer;
import io.dropwizard.logback.shaded.checkerframework.checker.nullness.qual.Nullable;

public class GameAuthorizer implements Authorizer<GameUser> 
{
    @Override
    public boolean authorize(GameUser user, String role, @Nullable ContainerRequestContext request) {
    	
        return user.getRoles() != null && user.getRoles().contains(role);
    	
    }
}
