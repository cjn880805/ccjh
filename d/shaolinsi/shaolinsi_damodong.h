//damodong.h

//Sample for room: ��Ħ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_damodong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ħ��");

	add_npc("shaolin_da_mo");

	add_door("����������", "����������", "�����´�Ħ��");

	set("long", "�����Ǵ�Ħ�Ŷ��������ǰ������ɮ�������Ħ���������£����˷�ˮ���أ���ס�������޵��ӣ��������ڣ����������·������ǧ�겻��֮������Ħ��ʦ���ڴ���������һ��ʮ�꣬�ڼ��������Կɿ��������ʱ�Ĵ�����̬�������ϵļ�����Ƭ�⣬���п���һ�" );

/*****************************************************
	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));
	set("objects",([
		"/clone/book/book-bamboo" : 1,
		CLASS_D("shaolin")+"/da-mo" : 1,
	]));
//	
********************************************/
};


ROOM_END;
