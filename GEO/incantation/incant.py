from textgenrnn import textgenrnn
from textgenrnn.utils import synthesize, synthesize_to_file
from os import system
import random

system('clear')

m1 = "knuth2notlargefile"
m2 = "illseen"
m3 = "zos"
m4= "invok"
m5= "allpiping"



def create_textgen(model_name):
    return textgenrnn(weights_path='{}_weights.hdf5'.format(model_name),
                     vocab_path='{}_vocab.json'.format(model_name),
                     config_path='{}_config.json'.format(model_name),
                     name=model_name)

model1 = create_textgen(m1)
model2 = create_textgen(m2)
model3 = create_textgen(m3)
model4 = create_textgen(m4)
model5 = create_textgen(m5)


#You can pass a list of models to generate from to synthesize. The rest of the input parameters are the same as generate.

models_list1 = [model2, model2, model1, model3, model4]
models_list2 = [model1, model1, model2, model3, model4]
models_list3 = [model3, model3, model1, model2, model4]
models_list4 = [model4, model4, model1, model2, model3]

models_list5 = [model1, model2]
models_list6 = [model1, model3]
models_list7 = [model1, model4]
models_list8 = [model2, model1]
models_list9 = [model2, model3]
models_list10 = [model2, model4]

models_list11 = [model2, model5]
models_list12 = [model5, model5, model1, model2, model3]
models_list13 = [model5, model5, model1, model2, model3, model4]
models_list14 = [model2, model2, model5]

models_list=[models_list1, models_list2, models_list3, models_list4, models_list5, models_list6, models_list7, models_list8, models_list9, models_list10, models_list11, models_list12, models_list13, models_list14]

prefix_list=["stone", "ill", "figment", "moon", "light", "zone", "bit", "she", "white", "dark", "death"]

#synthesize(models_list, n=10, progress=True)
#synthesize_to_file(models_list, "illsaidknuth.5.txt", n=10, max_gen_length=8000, temperature=0.5)
#synthesize(models_list11, n=10, max_gen_length=400, temperature=0.4, prefix="stone", progress=False)

for i in range(32):
    num=random.random()
    synthesize(random.choice(models_list), n=1, max_gen_length=800, temperature=num, prefix=random.choice(prefix_list), progress=False)

#synthesize(models_list1, n=8, max_gen_length=800, temperature=0.4, progress=False)
#synthesize(models_list2, n=8, max_gen_length=800, temperature=0.4, progress=False)
#synthesize(models_list3, n=8, max_gen_length=800, temperature=0.4, progress=False)
#synthesize(models_list4, n=8, max_gen_length=800, temperature=0.4, progress=False)


# or have list of start words... stone, zone, light, moon figment

#model1.generate_samples(n=10)

# doesn[t work... for words across knuth etc

# training biz

# model1txt="/content/drive/My Drive/new_writing/storyO"
# textgen = textgenrnn(name="storyOnotlargefile")
# textgen.reset()
# textgen.train_from_file(model1txt,
#                         new_model=True,
#                         rnn_bidirectional=True,
#                         rnn_size=64,
#                         dim_embeddings=300,
#                         num_epochs=50)

