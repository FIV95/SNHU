package com.gamingroom;

public class Entity {
  // Entity will be the parent class for Player, Team, and Game

  // The following fields are common to all entities
  private long id;
  private String name;

  // Constructor with no arguments
  public Entity() {
    this.id = 0;
    this.name = "";
  }
  // Constructor with an identifier and name
  public Entity(long id, String name) {
    this.id = id;
    this.name = name;
  }
  // Accessors
  public long getId() {
    return id;
  }
  public String getName() {
    return name;
  }

  // toString method
  @Override
  public String toString() {
    return "Entity [id=" + id + ", name=" + name + "]";
  }

}
