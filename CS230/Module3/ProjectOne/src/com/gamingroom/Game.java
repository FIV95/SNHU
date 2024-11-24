package com.gamingroom;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * A simple class to hold information about a game
 * 
 * <p>
 * Notice the overloaded constructor that requires
 * an id and name to be passed when creating.
 * Also note that no mutators (setters) defined so
 * these values cannot be changed once a game is
 * created.
 * </p>
 * 
 * @author coce@snhu.edu
 *
 */
public class Game extends Entity {
	
	List<Team> teams = new ArrayList<Team>();
	/**
	 * Hide the default constructor to prevent creating empty instances.
	 */
	private Game() {
	}

	/**
	 * Constructor with an identifier and name
	 */
	public Game(long id, String name) {
		super(id, name);
	}


    // this function adds a team to the game
    // it uses Java's built-in iterator to ensure each team is unique
    public void addTeam(Team team) {
			Iterator<Team> iterator = teams.iterator();
			while (iterator.hasNext()) {
					Team t = iterator.next();
					if (t.getId() == team.getId()) {
							System.out.println("Team " + team.getName() + " is already assigned to " + this.getName());
							return;
					}
			}
			this.teams.add(team);
	}


	// this function prints out the teams assigned to the game
	public void printTeams() {
		System.out.println("Teams assigned to " + this.getName() + ":");
		for (Team team : teams) {
			System.out.println(team.getName());
		}
	}


	@Override
	public String toString() {
		
		return "Game [id=" + this.getId() + ", name=" + this.getName() + "]";
	}

}
