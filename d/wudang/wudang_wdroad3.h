//wdroad3.h

//Sample for room: �䵱����·3
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wdroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱����·3");
	
//	add_npc("tiezhang_huiyi");             //zdd by zdn 2001-07-20


	add_door("�䵱����", "�䵱����", "�䵱����·3");
	add_door("�䵱����·2", "�䵱����·2", "�䵱����·3");

	set("long","������һ����������Ļ���·�ϣ�������ɭɭ�����֡������Ǻ������磬��˵���������˳�û�����ɾ������ϱ�һ��С����ͨ���������"); 
    
 
/*****************************************************

*****************************************************/
};


ROOM_END;
