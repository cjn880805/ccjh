ITEM_BEGIN(CIjiangzhumu);

virtual void create(int nFlag = 0)		
{
	set_name( "�����ľ");	
	set("long","һ��������С����ͨ��͸������������Ѫ��ˮ��ɺ�������ɷ�Ǻÿ�");
	set("no_get", "�㲻����ȥ������������������");
	set_weight(1);
	set("no_clean_up", 1);
	call_out(do_zhuguo, 600);	
};

static void do_zhuguo(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(env->query("zhuguo"))
	{
	case 0:
		tell_room(env, "\n\n$HIRֻ��һ�����ιŹ��������Ⱦ�ʯ��ʯ��������һ��������С����ͨ��͸������������Ѫ��ˮ��ɺ�������ɷ�Ǻÿ���֦���Ҷ�����������ż���۰׵Ļ�����\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 1:
		tell_room(env, "\n\n$HIR��ϸ��ʱ��ֻ��С���ϵļ������٣�����Ĵָ��󣬰׵�������覰��񣬶�������������š�\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 2:
		tell_room(env, "\n\n$HIRһ���������������˱ǣ������ˬ��С����������΢���н�����������չ������¶��Ʒ��Ļ��\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 3:
		tell_room(env, "\n\n$HIR�����淢Ũ��������С���ϵĻ��侹������ħ��㣬Խ��Խʢ��\nֻһ˲�ѱ�������յ���С�������ӳ ���������Ρ�\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 4:
		tell_room(env, "\n\n$HIR���꽥�ݣ�΢�紵����ƬƬ��ѩ��Ʈ�䣬ֻ�������ѽ���ۺ��С����\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 5:
		tell_room(env, "\n\n$HIRС����������ֻ������������飬Բ���ࡣ\n��������ɣ�С�������类�����˾�Ԫ�㣬����ή��������û���ʯ����ʧ������\n\n");
		env->del("zhuguo");
		load_item("zuguo")->move(env);
		destruct(me);
		break;
	}
}


ITEM_END;

