//daduhe.h

//Sample for room: ����Ǵ�ɺӱ�
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_daduhe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǵ�ɺӱ�");

	set("resident", "��Ū��");
	
	add_npc("dali_shennongdizi");        //add by zdn 2001-07-20


	add_door("�������Ū��", "�������Ū��", "����Ǵ�ɺӱ�");

	set("long", "��ɺ��������������ӹ���խ��ˮ���ļ������Ѷɹ���ֻ��Զ�����β��к�������������д��ɺӡ��˴��Ǻӹ�ת���ǳ̲��ˮ���Ի��������Կɼ����Ϻ�ˮ��ӿ��ȥ���԰����������ɼ����ϱ�ɽ������ʯ�ǡ�");
	
};


RESIDENT_END;
