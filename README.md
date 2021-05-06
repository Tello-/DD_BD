# DD_BD


 1) Clone Repo

 2) Open .sln in Visual Studio (windows)

 3) Set whichever project you'd like to launch as "startup project" (This can be done in the solution explorer by right-clicking the desired project and click "set as startup")
 
 4) Make sure that you are building in x86 and in debug mode.

I have included the entire SFML library in with the files. 
This is a relatively reasonable sized download but doing this allows me to share the solution with others in a simpler way.

Usually I'd look into making a CMAKE build file but in this case it's worth nobodies time.

### Character_Movement Project :

Meant to be a test project for some character movement mechanics. Currently it is mostly useless and broken. You can move a square around with the arrow keys.

### Collision_Map_and_Stamp :

Meant to test synching up a collision bitmap to a front end graphics bitmap. The inspiration is Worms pc game series. Click around and see what erases, right-click to flip to the collision bitmap view. Black is collidable and white is free space.

### GameLoop :

Just a gameloop. Mostly just a gameloop. This gameloop uses Gaffers last example @gaffer on games. The physics are updated at a static rate while the rendering is let free to render boundless. This allows for the EXACT same physics to result on a crappy computer vs a powerful computer in times of lag.

### GravityMovementCollisionGravityMovementCollision

This prototype is where I actually implemented the collision bitmap and the player colliding dynamically with the map. Space bar turns the gravity on (currently turns off after first collision detected). 'r' key resets the prototype project. Drag around in the "grass" just like in the map and stamp project, this version however dynamically detects collision with the player (square) object. In the same direction as the Worms PC games.

### Map_Mini_View

This is just an attempt at implementing a mini map for future use. Move the map with the arrow keys and note how it matches up to the full map view and marker.

### TheGame

