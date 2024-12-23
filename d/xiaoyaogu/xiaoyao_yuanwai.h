//xiaoyao_yuanwai.h Ժ��
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_yuanwai);

virtual void create()
{
	set_name( "Ժ��");

	add_door("��ң��СԺ", "��ң��СԺ", "��ң��Ժ��");	
	add_door("��ң��С·2", "��ң��С·2", "��ң��Ժ��");	
	add_door("��ң��С·3", "��ң��С·3", "��ң��Ժ��");	

};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu8_1") && me->query_temp("xy/renwu8_1") 
			&& !me->query("xy/renwu8_2") )
		{
			me->delete_temp("xy/renwu8_1");
			tell_object(me, "\n$HIC�����⼸�յ�Ѱ�ã�����Ȼû�еõ���ң�ӵİ����Ϣ�����¼ǹ�����۵İ�Σ��������Ȼ����������Ρ�");
			tell_object(me, "$HIC��Ȼһ���ƿ�֮��������һ�Ű�ɫ֮����ٵ��������Ŵ�����");
			tell_object(me, "$HIC������һ�������ס�������ϸһ����ԭ����һ�������˵�ֽ�š�");
			tell_object(me, "$HIC��һ������Ȼ����һ��ҩ����\n");
			me->set("xy/renwu8_2",1);//�õ��ָ��������ò��ҩ��
			load_item("xy_yaodan")->move(me);
		}
		else if(me->query("xy/renwu3") && me->query_temp("xy/renwu3_4") 
			 && !me->query_temp("xy/renwu3_5")&& !me->query_temp("xy/tanhuan4"))
		{
			//�����ң���Ƿ���Ժ�⣬��û�����NPC���һ��
			CContainer * env = load_room("��ң��Ժ��");
			CContainer * xiaoyaozi=env->present("xiaoyao zi");
			if(!xiaoyaozi)
			{
				CChar * XyNpc = load_npc("xy_xiaoyaozi");
				XyNpc->move(load_room("��ң��Ժ��"));
			}
			me->disable_player("������");
			me->call_out(do_tanhua, 1);
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(me->query_temp("xy/tanhuan4"))
	{
	case 0:
		tell_object(me, "\n��ңŮ������ң��һ��$HIY����ѩ��$COM��");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "��ң�ӽ�$HIY����ѩ��$COM�Ļ��꾡��ժ�£�����һ��ľ���У�Ȼ��ӻ���ȡ��һֻСҩƿ����ľ��������һЩҩ�ۡ�");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, "��һ�����������ܳ���һ��ǳ��ɫ��$HIYѩ��֭$COM��");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "��ң��ι�����һ��$HIY����ѩ��֭$COM��Ȼ��˫��������ı���Ϊ�������ƹ����Դ߶�ҩ��������綾��");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "��ֻ��������һ�ȣ�һ���������ֱ�������Ѹ���ޱȵĳ����Ŀڡ�");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "�������Խ��Խ������Խ��Խ�ͣ�ֱ����������Ѩ����о�������������Ҫ����һ����ʹ���ѵ���");
		me->add_temp("xy/tanhuan4",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, "��Ȼ���ͷһ��һ����Ѫ���¶�������ǰһ�ڣ����ʹ�ȥ��");
		me->delete_temp("xy/tanhuan4");
		if(me->query_temp("xy/renwu3_0"))
			me->delete_temp("xy/renwu3_0");
		me->set_temp("xy/renwu3_5",1);//��������е�֩�붾
		me->enable_player();
		me->apply_condition("scorpion_poison", 0);
		me->unconcious();
		me->set("hp",me->query("eff_hp"));
		me->move(load_room("��ң��С��"));
		//�����ңŮ�Ƿ��ڷ��䣬�������NPC������
		env = load_room("��ң��Ժ��");
		CContainer * xiaoyaonv=env->present("xiao yao nv");
		if(xiaoyaonv)
		{
			destruct(xiaoyaonv);
		}
		//�����ң���Ƿ��ڷ��䣬�������NPC������
		CContainer * xiaoyaozi=env->present("xiaoyao zi");
		if(xiaoyaozi)
		{
			destruct(xiaoyaozi);
		}
		break;
	}
}
XiaoYao_END;
