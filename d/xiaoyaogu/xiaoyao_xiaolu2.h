//xiaoyao_xiaolu2.h С·2
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_xiaolu2);

virtual void create()
{
	set_name( "С·2");
	set("monster_chance",60);
	set("no_autosave",1);

	add_door("��ң��Ժ��", "��ң��Ժ��", "��ң��С·2");	
	add_door("��ң��С·1", "��ң��С·1", "��ң��С·2");	

};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu6") && !me->query("xy/renwu6_1") && !me->query("xy/renwu7")
			&& !me->query_temp("xy/renwu6_5") && !me->query_temp("xy/renwu6_1"))
		{
			CChar * XyNpc = load_npc("xy_licanghai1");
			XyNpc->move(load_room("��ң��С·2"));
			XyNpc->set("owner",me->id(1));
			XyNpc->set_leader(me);
			me->set_temp("xy/renwu6_1",1);//��׺����������ߧ����

			tell_object(me,"\n$HIC��׺���������������˵�˵����");
			tell_object(me,"$HIC�����������ã�ʦ���Ѿ��Լ�����ߧ����ȥ��һ����ˣ����������ţ�������͵�Ե�ȥ�������ڱ�һ�����ص�ס�ˣ��������ҽ�ȥ�𣡡�\n");
			tell_object(me,"$HIY��׺���ʼ�������ж���");
		}
	}
}

XiaoYao_END;
