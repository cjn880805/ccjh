//huanghe4.h

//Sample for room: �ƺӰ���4
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӰ���4");
	
	add_npc("monster_28k");        //add by zdn 2001-07-14
	add_npc("pub_lisheng"); 

	add_door("�ƺӰ���3", "�ƺӰ���3", "�ƺӰ���4");
	add_door("�ƺӰ���5", "�ƺӰ���5", "�ƺӰ���4");

	set("long","�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ��ƺ�����������ܵ�����̩ɽ���赲��ת���򱱡�");
	

};


CHANGAN_END;
