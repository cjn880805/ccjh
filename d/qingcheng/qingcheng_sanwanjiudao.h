//sanwanjiudao.h

//Sample for room: �������ŵ�
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_sanwanjiudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ŵ�");
	
	add_npc("pub_bing");          //add by zdn 2001-07-14


	add_door("������幬", "������幬", "�������ŵ�");
	add_door("��ǳ�����", "��ǳ�����", "�������ŵ�");


    

/*****************************************************

*****************************************************/
};


ROOM_END;
