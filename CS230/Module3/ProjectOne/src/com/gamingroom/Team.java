package com.gamingroom;
import java.util.List;
import java.util.ArrayList;

/**
 * A simple class to hold information about a team
 * this class inherits from the Entity class
 * this class has a relationship with the Player class
 * <p>
 * Notice the overloaded constructor that requires
 * an id and name to be passed when creating.
 * Also note that no mutators (setters) defined so
 * these values cannot be changed once a team is
 * created.
 * </p>
 * @author coce@snhu.edu
 *
 */
public class Team extends Entity {
	
	// Dynamic list of players on the team
	List<Player> players = new ArrayList<Player>();
	/*
	 * Constructor with an identifier and name
	 */
	public Team(long id, String name) {
		// super allows us to call the constructor of the parent class
		super(id, name);
	}

	// method to add a player to the team
	public void addPlayer(Player player) {
		players.add(player);
	}

	@Override
	public String toString() {
		return "Team [id=" + this.getId() + ", name=" + this.getName() + "]";
	}
}
