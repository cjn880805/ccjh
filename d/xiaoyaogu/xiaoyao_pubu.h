//xiaoyao_pubu.h �ٲ�
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_pubu);

virtual void create()
{
	set_name( "�ٲ�");

	add_door("��ң�ȷ������������", "��ң�ȷ������������", "��ң���ٲ�");
	add_door("��ң�Ⱦ��º�", "��ң�Ⱦ��º�", "��ң���ٲ�");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu6") && me->query_temp("xy/renwu6_5") &&
			!me->query("xy/renwu7") && !me->query_temp("xy/renwu6_6"))
		{
			CChar * XyNpc = load_npc("xy_liqiouheng");
			XyNpc->move(load_room("��ң���ٲ�"));
			XyNpc->set("owner",me->id(1));
			XyNpc->set_leader(me);

			me->set_temp("xy/renwu6_6",1);//������۽�����ߧ����
			me->delete_temp("xy/renwu6_2");
			
			tell_object(me,"\n$HIC������ʵ�����ʦֶ��������ʦ�����𣿡�");
			tell_object(me,"$HIC��������ʦ�������Ż������Сʦ��ѧ�����أ���");
			tell_object(me,"$HIC����ۡ�Ŷ����һ����������Щ�����������鷳ʦֶҲ���ҽ���һ�˰ɣ���\n");
			tell_object(me,"$HIY����ۿ�ʼ�������ж���");
		}
	}
}

XiaoYao_END;
