//wdroad2.h

//Sample for room: �䵱����·2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wdroad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱����·2");
	
//	add_npc("tiezhang_qqren");        //add by zdn 2001-07-20

	add_door("�����ݵ�", "�����ݵ�", "�䵱����·2");
	add_door("�䵱����·3", "�䵱����·3", "�䵱����·2");
	add_door("��ɽ����ɽ��", "��ɽ����ɽ��", "�䵱����·2");

    
 
/*****************************************************

*****************************************************/
};


ROOM_END;
