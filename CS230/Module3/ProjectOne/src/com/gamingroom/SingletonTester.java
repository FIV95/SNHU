package com.gamingroom;

/**
 * A class to test a singleton's behavior
 * 
 * @author coce@snhu.edu
 */
public class SingletonTester {

    public void testSingleton() {
        
        System.out.println("\nAbout to test the singleton...");
        
        // Obtain local reference to the singleton instance
        GameService service = GameService.getInstance();
        
        // Add some games for testing
        Game game1 = service.addGame("TestGame1");
        Game game2 = service.addGame("TestGame2");

        // Test retrieving a game by name
        Game retrievedGame1 = service.getGame("TestGame1");
        assert retrievedGame1 != null : "Failed to retrieve game by name";
        assert game1.getId() == retrievedGame1.getId() : "Game ID mismatch";

        // Test retrieving a game by id
        Game retrievedGame2 = service.getGame(game2.getId());
        assert retrievedGame2 != null : "Failed to retrieve game by id";
        assert "TestGame2".equals(retrievedGame2.getName()) : "Game name mismatch";

        // Test retrieving a non-existent game by name
        try {
            service.getGame("NonExistentGame");
            assert false : "Expected an exception for non-existent game by name";
        } catch (IllegalArgumentException e) {
            // Expected exception
						System.out.println("Expected exception for non-existent game by name");
        }

        // Test retrieving a non-existent game by id
        try {
            service.getGame(9999L);
            assert false : "Expected an exception for non-existent game by id";
        } catch (IllegalArgumentException e) {
            // Expected exception
						System.out.println("Expected exception for non-existent game by id");
        }

        // A simple for loop to print the games
        for (int i = 0; i < service.getGameCount(); i++) {
            System.out.println(service.getGame(i));
        }

        // Creates new game, team, and player objects and prints to test
        Game game3 = service.addGame("TestGame3");
        Team team1 = new Team("Team1");
        Team team2 = new Team("Team2");
        game3.addTeam(team1);
        game3.addTeam(team2);
        Player player1 = new Player("Player1");
        Player player2 = new Player("Player2");
        Player player3 = new Player("Player3");
        Player player4 = new Player("Player4");
        Player player5 = new Player("Player5");
        Player player6 = new Player("Player6");
        Player player7 = new Player("Player7");
        Player player8 = new Player("Player8");
        team1.addPlayer(player1);
        team1.addPlayer(player2);
        team1.addPlayer(player3);
        team1.addPlayer(player4);
        team2.addPlayer(player5);
        team2.addPlayer(player6);
        team2.addPlayer(player7);
        team2.addPlayer(player8);
        game3.printTeams();
        System.out.println();
        team1.printPlayers();
        System.out.println();
        team2.printPlayers();
        System.out.println();
        System.out.println(game3);
        System.out.println();


        System.out.println("All tests passed.");
    }
}