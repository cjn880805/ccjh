//jiashan.h

//Sample for room: ��ɽ��ɽС��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_jiashan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��ɽС��");
	
	add_npc("huashan_shidaizi");      //add by zdn 2001-07-20


	add_door("��ɽ��Ժ", "��ɽ��Ժ", "��ɽ��ɽС��");

	set("long", "������һ��С԰�ӣ���ͷ�и�С���������ܲ��м�ɽ��������԰����������ʱ��ˮ����Ϫ���У�����ˮ���������������̰��ö���ˮ��������̧ͷ������ֻ��Զ����ɽ���죬�������֣��꾰��Ȥ���");  
    
 
/*****************************************************
	set("exits",([
		"east" : __DIR__"houyuan",
	]));
********************************************/
};


ROOM_END;
