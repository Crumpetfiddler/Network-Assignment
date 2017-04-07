#pragma once
#include <glm/glm.hpp>
#include <RakPeerInterface.h>
#include <BitStream.h>
#include "GameMessages.h"

class Client;

class GameObject
{
public:

	int m_myClientID;
	int health;
	int currentHealth;
	bool dead = false;
	int rotation;		//0 = up, 1 = right, 2 = down, 3 = left

	float timer;
	float respawn_Point_A = 9.0f;
	float respawn_Point_B = 9.0f;
	float respawn_Point_C = -9.0f;
	float respawn_Point_D = -9.0f;

	glm::vec3 position;
	glm::vec4 colour;


	GameObject();
	virtual ~GameObject();

	static glm::vec4 getColour(int id);
	void updateHealth(RakNet::RakPeerInterface * pPeerInterface, Client* c);
	void Respawn();

#ifndef NETWORK_SERVER
	bool updateTranforms(float deltaTime, Client * client);

#endif

	void Read(RakNet::Packet* packet);
	void Write(RakNet::RakPeerInterface* pPeerInterface, const RakNet::SystemAddress& address, bool broadcast);

	void Draw();
};

