//yzjw_jiaowai4.h

//Sample for room:  ��������4
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_jiaowai4);
virtual void create()			//Call it when Room Create
{
	set_name( "��������4");

	add_npc("gaibang_zhao_gouer");	

	add_door("��������5","��������5","��������4");
	add_door("��������3","��������3","��������4");

    set("long","���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ�����������������ĵط��������߳��ε����");
 
};


ROOM_END;
