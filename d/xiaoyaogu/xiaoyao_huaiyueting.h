//xiaoyao_huaiyueting.h ����ͥ
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_huaiyueting);

virtual void create()
{
	set_name( "����ͥ");

	add_door("��ң��׷�¹۴���", "��ң��׷�¹۴���", "��ң��׷�¹ۻ���ͥ");
	add_door("��ң��׷�¹۾�˼ͥ", "��ң��׷�¹۾�˼ͥ", "��ң��׷�¹ۻ���ͥ");
	add_door("��ң��׷�¹����䳡", "��ң��׷�¹����䳡", "��ң��׷�¹ۻ���ͥ");

};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu5") && !me->query("xy/renwu6")
		&& me->query("xy/renwu5_1") && !me->query_temp("xy/renwu5_1"))
		{
			CContainer * env = load_room("��ң��׷�¹ۻ���ͥ");
			CContainer * Xy_Npc=env->present("xiaoyao zi");
			CChar * XyNpc;
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_xiaoyaozi");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("li qiou heng");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_liqiouheng");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("li cang hai");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_licanghai1");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("shikong zixu");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_shikong");
				XyNpc->move(env);
			}
			Xy_Npc=env->present("qing feng");
			if(!Xy_Npc)
			{
				XyNpc = load_npc("xy_qingfeng");
				XyNpc->move(env);
			}
			tell_object(me,"\n$HIR���˾������˵������������˾�չ�������\n");
			me->set_temp("xy/renwu5_1",1);//�μ���˾�չ���
		}
	}
}

XiaoYao_END;
