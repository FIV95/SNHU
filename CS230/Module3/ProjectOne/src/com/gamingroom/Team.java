package com.gamingroom;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

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

	// Constructor with only a name, the id is generated
	public Team(String name) {
		super(GameService.getInstance().getNextTeamId(), name);
	}

	// method to add a player to the team
	// this method uses the built in iterator to ensure each player is unique
	public void addPlayer(Player player) {
		// iterator to iterate through the list of players
		// if the player is already on the team, it will print a message
		Iterator<Player> iterator = players.iterator();
		while (iterator.hasNext()) {
			Player p = iterator.next();
			if (p.getId() == player.getId()) {
				System.out.println("Player " + player.getName() + " is already on " + this.getName());
				return;
			}
		}
		// if the player is not on the team, it will add the player to the team
		players.add(player);
	}

	// method to print the players on the team
	public void printPlayers() {
		System.out.println("Players on " + this.getName() + ":");
		for (Player player : players) {
			System.out.println(player.getName());
			System.out.println(player.getId());
		}
	}

	@Override
	public String toString() {
		return "Team [id=" + this.getId() + ", name=" + this.getName() + "]";
	}
}
