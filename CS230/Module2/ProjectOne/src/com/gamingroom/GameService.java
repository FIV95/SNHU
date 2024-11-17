package com.gamingroom;

// importing built in iterator
import java.util.Iterator;
import java.util.ArrayList;
import java.util.List;

/**
 * A singleton service for the game engine
 * 
 * @author coce@snhu.edu
 */
public class GameService {

	/**
	 * A list of the active games
	 */
	private static List<Game> games = new ArrayList<Game>();

	/*
	 * Holds the next game identifier
	 */
	private static long nextGameId = 1;
	// unique instance private member
	private static GameService instance = null;

	// FIXME: Add missing pieces to turn this class a singleton 
	// Private constructor prevents instantiation from other classes
	private GameService() {
	}
	// Breakdown of the singleton pattern
	// We make the private data member instance null
	// when we call the getInstance method, we check if the instance is null
	// if it still is null, we create a new instance of the GameService
	// if it is not null, we return the instance that was created
	// this way we only have one instance of the GameService
	// The Instance will host the instances of games
	// This ensures all memory is managed in one place set by the singleton pattern
	
	// Public method to get the singleton instance
	public static GameService getInstance() {
		if (instance == null) {
			instance = new GameService();
		}
		return instance;
	}

	// Breakdown of the Iterator pattern
	// The iterator pattern is used to iterate through a collection of objects
	// In this case its our list of games
	// We use the iterator to iterate through the list of games
	// The iterator pattern abstracts the details of the search
	// and allows us to iterate through the list of games
	// by the simple nature of .next() and .hasNext()

	/**
	 * Construct a new game instance
	 * 
	 * @param name the unique name of the game
	 * @return the game instance (new or existing)
	 */
	public Game addGame(String name) {
			// instantiate the iterator
			Iterator<Game> gameIterator = games.iterator();
			// while loop to iterate through the games
			while (gameIterator.hasNext()) {
					Game game = gameIterator.next();
					// if the game name is equal to the name passed in
					if (game.getName().equals(name)) {
							return game;
					}
			}
	
			// if not found, make a new game instance and add to list of games
			Game game = new Game(nextGameId++, name);
			games.add(game);
	
			// return the new/existing game instance to the caller
			return game;
	}

	/**
	 * Returns the game instance at the specified index.
	 * <p>
	 * Scope is package/local for testing purposes.
	 * </p>
	 * @param index index position in the list to return
	 * @return requested game instance
	 */
	Game getGame(int index) {
		return games.get(index);
	}
	
	/**
	 * Returns the game instance with the specified id.
	 * 
	 * @param id unique identifier of game to search for
	 * @return requested game instance
	 */
	public Game getGame(long id) {
			// instantiate the iterator
			Iterator<Game> gameIterator = games.iterator();
			// while loop to iterate through the games
			while (gameIterator.hasNext()) {
					Game game = gameIterator.next();
					// if the game id is equal to the id passed in
					if (game.getId() == id) {
							return game;
					}
			}
			// throw catch if the game is not found
			throw new IllegalArgumentException("Game not found");
	}

		// FIXME: Use iterator to look for existing game with same id
		// if found, simply assign that instance to the local variable


	/**
	 * Returns the game instance with the specified name.
	 * 
	 * @param name unique name of game to search for
	 * @return requested game instance
	 */
	public Game getGame(String name) {
			// instantiate the iterator
			Iterator<Game> gameIterator = games.iterator();
			// while loop to iterate through the games
			while (gameIterator.hasNext()) {
					Game game = gameIterator.next();
					// if the game name is equal to the name passed in
					if (game.getName().equals(name)) {
							return game;
					}
			}
			// throw catch if the game is not found
			throw new IllegalArgumentException("Game not found");
	}

	/**
	 * Returns the number of games currently active
	 * 
	 * @return the number of games currently active
	 */
	public int getGameCount() {
		return games.size();
	}
}
