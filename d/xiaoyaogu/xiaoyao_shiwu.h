//xiaoyao_shiwu.h ʯ��
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_shiwu1);

virtual void create()
{
	set_name( "ʯ��");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);
	add_npc("xy_xiaoyaozi");

	add_door("��ң��������", "��ң��������", "��ң��ʯ��");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") )
		{
			CContainer * env=me->environment();
			CContainer * XyNpc=env->present("xiaoyao zi");
			if(XyNpc)
				destruct(XyNpc);
		}
		else if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_6") && !me->query("xy/renwu4_42") )
		{
			tell_object(me,"\n$YEL��ɽ���ѱ���һ����ɽ�����Ƶ���ʽ���ɻ������ң�ӣ���ʦ�ܣ������ҿ�����ʦ�����ڵ���һʽ����������������ʼ���޷��ڻ��ͨ�����֪��ʲôԭ���𣿡�");
			tell_object(me,"$YEL��ң������üͷ˼����һ�����������ɽ���ѵ��ֱȻ���һ�£����ƺ�Ӧ�������Ÿ����ʡ���");
			tell_object(me,"$YEL������˵�����ⴳ��������Ц�ݵ�����ۡ�");
			tell_object(me,"$YEL�������ס��ң�ӵ���˵������ʦ�磬�ҽ��մ�����ɽ�е�һ���ɲ�Ů��ѧ���һ�����ӣ�������˼�������ҳ�����������");
			tell_object(me,"$YEL˵�ϣ�������ң�ӵ��ֱ��ߡ�");
			tell_object(me,"\n$YEL��ɽ����ֻ�޵�������ҧ�����صغ���һ����\n");

			me->set("xy/renwu4_42",1);
			me->add("xy/��ɶ�",1);
		}
	}
}

XiaoYao_END;
