ITEM_BEGIN(CIjieyuling)

void create(int nFlag = 0)		
{
	set_name("����������", "jieyu ling");
    set_weight(1);
    set("unit", "��");
    set("long", "����һ���Ϻ�ɫ�����ƣ��������һ��һ����");
	set("material", "steal");
	set("no_drop",1);
	set("no_sell",1);
};

//��������
void init()
{
	CContainer * env = environment();

	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		return;
	}
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || target == me)
		return notify_fail("��Ҫ��˭ʹ�ã�");

	if (me->is_fighting())
		return notify_fail("�����޷�ʹ�õ��������");

	if (me->query_temp("fool/finish"))
		return notify_fail("���Ѿ�������񣬻������ȥ������ĥ��ʲô��");

	if( me->is_busy())
		return notify_fail("�����ں�æ��");

	char msg[255];	
	int flag=0;

	tell_object(me, snprintf(msg, 255, "$HIG����������������%s��",target->name()));

	if (target->object_id() == me->query_temp("fool/doing") && random(me->query_int()) > 20)
	{
		switch(random(5)) 
		{
		case 0:
			snprintf(msg, 255, "$WHT�㷢��%s��Ȼ��ͷһ�ͣ��ƺ���ܿ����Ŀ�⡣",target->name());
            break;
		case 1:
			snprintf(msg, 255, "$WHT�㷢��%s��Ȼ���˸����£�������ɫ��",target->name());
			break;
		case 2:
			snprintf(msg, 255, "$WHT�㷢��%s̫��Ѩ�߸߷����ƺ��Ǹ�������ˡ�",target->name());
			break;
		case 3:
			snprintf(msg, 255, "$WHT�㷢��%s����Ĺ����ҵģ���������һ������",target->name());
			break;
		case 4:
			snprintf(msg, 255, "$WHT�㷢��%s�����о���һ���������ֱ��һ��ãȻ��",target->name());
			break;
		}

		flag=1;
	}  
	else
	{
		switch(random(11)) 
		{
		case 0:
			snprintf(msg, 255, "$HIGֻ��%s����üŪ�ۣ�ɫ���ԵĶ���������",target->name());
			break;
			
		case 1:
			snprintf(msg, 255, "$HIGֻ��%s������Ƽ��ݣ��������",target->name());
			break;
			
		case 2:
			snprintf(msg, 255, "$HIGֻ��%s���΢�죬һ�����ߵ�ģ����",target->name());
                     break;
		case 3:
			snprintf(msg, 255, "$HIGֻ��%s�������⣬�������硣",target->name());
			break;
			
		case 4:
			snprintf(msg, 255, "$HIGֻ��%s��ʹ�������޵���������Ƶġ�",target->name());
			break;

		case 5:
			snprintf(msg, 255, "$HIGֻ��%s���㽩Ӳ������ɢ���Ž�������",target->name());
			break;

		case 6:
			snprintf(msg, 255, "$HIGֻ��%s���ޱ��飬����ľ����",target->name());
			break;
			
		case 7:
			snprintf(msg, 255, "$HIGֻ��%s���ü��������Ŀ���թ��",target->name());
			break;
         
		case 8:
			snprintf(msg, 255, "$HIGֻ��%s��Ц���������ϼ���һ˿��Ц��",target->name());
			break;
                
		case 9:
        	snprintf(msg, 255, "$HIGֻ��%sͦ�ص��ǣ�һ����������ɫ��",target->name());
	        break;
                
		case 10:
			snprintf(msg, 255, "$HIGֻ��%s���������ݣ�һ���������ɫ��",target->name());
			break;
		}
	}
	
	tell_object(me,msg);
	me->start_busy(2);

	if (! flag) return 1;
	
	//�ɹ����ҵ��ˡ�

	message_vision("$HIW$N����$n��Цһ���������µİ��ӷ��ˣ�����ʵʵ������һ�ˡ�",me,target);
	message_vision("$HIY$N��Цһ����������û��ô���ף�",target);
	destruct(target);

	flag = 11 + me->query("fool/diff");	//�Ѷ�ϵ��
	
	//����һ�����
	CNnpcmirror * monster = (CNnpcmirror *)load_npc("monster_jieyu");
	monster->make_mirror(me, flag);
	monster->set_name( me->querystr_temp("fool/name"));
	monster->set("foolid", me->query_temp("fool/doing"));
	monster->set_weight(50000000);
	monster->move(me->environment());
	monster->kill_ob(me);

	monster->call_out(do_die, 400+random(100));	

	return 1;
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

ITEM_END;