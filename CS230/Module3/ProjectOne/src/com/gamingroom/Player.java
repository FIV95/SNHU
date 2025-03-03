package com.gamingroom;

/**
 * A simple class to hold information about a player
 * this class inherits from the Entity class
 * <p>
 * Notice the overloaded constructor that requires
 * an id and name to be passed when creating.
 * Also note that no mutators (setters) defined so
 * these values cannot be changed once a player is
 * created.
 * </p>
 * @author coce@snhu.edu
 *
 */
public class Player extends Entity {
	
	/*
	 * Constructor with an identifier and name
	 */
	public Player(long id, String name) {
		// super allows us to call the constructor of the parent class
		super(id, name);
	}

	// Constructor with only a name, the id is generated
	public Player(String name) {
		super(GameService.getInstance().getNextPlayerId(), name);
	}

	@Override
	public String toString() {
		return "Player [id=" + this.getId() + ", name=" + this.getName() + "]";
	}

}
