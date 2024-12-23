//cai.h ����
//�ز� 2002��12��30

FOOD_BEGIN(CIcaiyao);

virtual void create(int nFlag = 0)
{
	static char cai[45][20]={"Ѭ����","���Ӽ�","������","�廨����","�����ض�","��������","������˿","���ͷ�Ƭ","�������","���ʹ೦","��˿Ѭ��","�Ǵ��Ź�","������˿","������Ϻ","ϸ��ͷ��","���㶬��","��������","��䶹��","���ʸ���","ʱ���߲�","��Ƥ��Ѽ","��������","���Ŷ���","ܽ�ظ���","�ɰ��Ｙ","ܽ��з��","����Ұ��","�����Ｆ","����Ǭ��","��������","���˲ݹ�","�ٻ�Ѽ��","ެ������","��������","��֭ެ��","ɽ��ާ��","�����и�","�Ǵ׺�ź","��ը����","�װ��㴽","���㱫��","��������","�������","�����ƹ�","��˿�㽶"};
	
	int index=random(45);
	set_name(cai[index]);
	
	set_weight(20000);
	set("unit", "��");
	char msg[255];
	
	set("long",snprintf(msg, 255,"����һ�����˴������εġ�%s��",cai[index]));
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	long i;
	long e;
	
	i=current_time;
	e=me->query_temp("cao/overtime");
	if (i<e)
	{
		if(EQUALSTR(who->id(1) , querystr("cao/id")) && EQUALSTR(who->name(1), querystr("cao/name")) 
			&& EQUALSTR((who->environment())->name(1) , querystr("cao/map")) &&EQUALSTR(me->id(1) , querystr("owner1"))  )
		{
			static char hows[29][255] = {
				"����Ҹ���",
					"��������",
					"��������",
					"�����̵�",
					"��Ϊ�����",
					"��ͷ������",
					"�м����ܵ�",
					"������",
					"�����û��������",
					"ׯ�ϵؿ��Ŵ�ң�Ȼ���¸ҵ�",
					"���������",
					"����������",
					"�������ɵ�",
					"�������ۣ�",
					"ҡͷ���Ե�",
					"����һЦ��",
					"����һ��",
					"���ֱ��ŵ�",
					"��ͷ���Ե�",
					"������Ц����������",
					"�ƿ����ˣ��ںü�ʽ��",
					"��ͷ�����",
					"�˷ܵ���ͷ�󺹣�",
					"��Ƽ��ݵ�",
					"Ĩȥ�۽ǵ��Ứ��",
					"����֣�һ��ţ�",
					"������צ��",
					"ʮ��ǫ���",
					"�ߵ�����ͨ�죬",
			};
			
			static char manners [27][255]  = {
				"��$HIC��$n��$COM�������ﷴ�����˼��£�",
					"��$HIC��$n��$COM�ڵ��Ϸ��ض�⣬",
					"��$HIC��$n��$COM��ǽ���ص�һ���ҿ���",
					"��$HIC��$n��$COM���Ŀ���ϸů��һ�£�",
					"��$HIC��$n��$COM���͹���Ѹ��һը��Ȼ��",
					"������$HIC��$n��$COM��",
					"ʹ��˺��$HIC��$n��$COM��һ��һ���",
					"��$HIC��$n��$COM������Ĩ��һ�����ެ�ѽ���",
					"����$HIC��$n��$COMպ�ź��ĺ��ǣ�",
					"��$HIC��$n��$COM������һ����Σ�",
					"��$HIC��$n��$COM���������Ƭ��ƹϣ�",
					"��$HIC��$n��$COM�ڽ�����һպ��Ʒ��ζ",
					"��$HIC��$n��$COM�����������һ�㣬���е�",
					"��$HIC��$n��$COM�ڿ�ˮ��һ�ݣ�����",
					"��$HIC��$n��$COM�ڻ���һ�ǣ��Ͻ�",
					"��һ�������п�$HIC��$n��$COM��",
					"��������$HIC��$n��$COM",
					"��һ�����˾�����$HIC��$n��$COM�ϣ�",
					"��$HIC��$n��$COM������ˮϴ�øɸɾ�����",
					"��$HIC��$n��$COM�����˰��죬",
					"��$HIC��$n��$COM����һ��ե��˿��",
					"��$HIC��$n��$COM�Ϲ�һ��������ң�",
					"��$HIC��$n��$COM�ʹн���ĩ����һ��",
					"��$HIC��$n��$COM���飬�������ˣ�",
					"��$HIC��$n��$COM�г�С�飬���ϼ����������ȵ����͹��ﳴ�ɹ���$HIC��$n��$COM��",
					"��$HIC��$n��$COM�Ž�������Ͻ��ͺ���С�����ɺ���$HIC��$n��$COM��",
					"��$HIC��$n��$COM�����ڹ��ﵹ�������ͳ�һ���Ǵ�$HIC��$n��$COM��",
			};
			
			static char actions [24][255] = {
				"�ſ�ӣ��С��������ȥ",
					"����Ƭ���촽ҧסֻһ����������ȥ",
					"һ�����������ȥ",
					"��������ƹƹ����һ��",
					"����üͷʹ�ļ��׵س�����ȥ",
					"������һ�ӣ�������Ӱȵ�һ����ס",
					"���������ʹ����һ��",
					"Ӳ��ͷƤ����׽���س�����ȥ",
					"��ર����ü���۵س�����ȥ",
					"�������������ݱ�������ڵ�������ȥ",
					"������ζ����ָ��������ȥ",
					"����û�����첱�ڽŵ�������ȥ",
					"�ʷʵ�����һ��",
					"��������Ͳ����������˶���",
					"һ���ҧ�ų��˲�����",
					"�ſ�Ѫ���ڣ�������������һ��",
					"�Ե��񾭴�����ð����",
					"�Ե������񶫵�����",
					"�Ե������������",
					"�Ե����ߵ��������",
					"�Ե÷����������ذ�",
					"���̻��ʵط�����������ҽ�������ȥ",
					"��������ش����������ֻһ�����������������������ȥ",
					"ʹ�಻���س�����ȥ",
			};
			
			char msg[255];
			message_vision (snprintf(msg, 255,"\n$HIC$N�Ѿ���������������%s%s%s��",hows[random(29)],manners[random(27)],actions[random(24)]), who,this);

			me->delete_temp("cao/id");
			me->delete_temp("cao/name");
			me->delete_temp("cao/map");
			me->delete_temp("cao/overtime");
			me->add_temp("cao/count",1);

			reward_exp(me);
			
			destruct(this);
			return 1;
		}
	}
	return notify_fail("���ܶԶԷ�ʹ�������Ʒ��");
}

//������
void reward_exp(CChar * me)
{
	char msg[255], tmp[80];

	int exp = 20+me->query("cao/count")+random(30);
	me->add("combat_exp", exp);
	int money=20+random(me->query("cao/count")+30);
	CMoney::Pay_Player(me, money);

	if(me->query_temp("cao/count")>200)
		me->delete_temp("cao/count");

	if(me->query_temp("weight"))
	{
		me->set_weight(me->query_temp("weight"));
		me->delete_temp("weight");
	}
	me->delete_temp("no_fei");
	
	tell_object(me, snprintf(msg, 255, "$HIR�����������ƹ���Ͳ����񣬻����%s�㾭�顢%d�Ľ������ң�\n", chinese_number(exp, tmp),money));

	me->FlushMyInfo();
}
FOOD_END;
