cmake_minimum_required(VERSION 3.0)

project(flight)


set (SRCS
	b747.c  
	color.c  
	draw_logo.c  
	f16.c   
	f18.c     
	graph.c   
	main.c   
	meters.c  
	p38.c   
	uflight.c
	c150.c  
	demo.c   
	f15.c        
	f16w.c  
	flight.c  
	irisgl.c  
	maths.c  
	object.c  
	p38w.c
)

set (HEADERS
	bitmap.h  
	demo.h      
	f16_points.h  
	graph.h   
	main.h   
	meters.h   
	p38.h         
	planes.h    
	sgilogo.h
	colors.h  
	f16_defs.h  
	flight.h      
	irisgl.h  
	maths.h  
	objects.h  
	p38_points.h
	uflight.h
	gamestruct.h
)

add_executable(flight ${SRCS} ${HEADERS})
target_link_libraries(flight m)

set (OpenGL_GL_PREFERENCE LEGACY)
find_package (OpenGL)
if (OpenGL_OpenGL_FOUND AND OPENGL_GLU_FOUND)
	
  	target_include_directories(flight PUBLIC ${OPENGL_INCLUDE_DIR})
  	target_link_libraries (flight ${OPENGL_LIBRARIES})
else ()
  	# Sinon, nous affichons un message
  	message(FATAL_ERROR "opengl and glu not found")
endif ()

# Recherche la dépendance externe
find_package (GLUT)
if (GLUT_FOUND)
	message(STATUS "add glut dependencies")
  	target_include_directories(flight PUBLIC ${GLUT_INCLUDE_DIRS})
  	target_link_libraries (flight ${GLUT_LIBRARY})
else ()
  	message(FATAL_ERROR "glut not found")
endif ()

